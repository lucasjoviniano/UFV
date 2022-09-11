defmodule ListaUm do
  require Integer

  @spec media(list) :: float
  def media(values) when is_tuple(values) do
    media(Tuple.to_list(values))
  end

  def media(values) do
    values
    |> Enum.sum()
    |> Kernel./(Kernel.length(values))
  end

  def mediana(values) when is_list(values), do: _mediana(List.to_tuple(Enum.sort(values)))

  defp _mediana(values) when Integer.is_odd(Kernel.tuple_size(values)) do
    elem(values, Kernel.floor(Kernel.tuple_size(values) / 2))
  end

  defp _mediana(values) do
    media([
      elem(values, Kernel.floor(Kernel.tuple_size(values) / 2)),
      elem(values, Kernel.floor(Kernel.tuple_size(values) / 2 - 1))
    ])
  end

  @spec moda(any) :: list(Integer)
  def moda(values) do
    frequencies =
      values
      |> Enum.reduce(%{}, fn item, counts ->
        Map.update(counts, item, 1, &(&1 + 1))
      end)

    frequencies
    |> Enum.filter(fn {_, value} ->
      value == Enum.max(Map.values(frequencies))
    end)
    |> Enum.map(&elem(&1, 0))
  end

  def ponto_medio(values) do
    values
    |> Enum.min_max()
    |> media()
  end

  def amplitude(values, class_size \\ 1) do
    range =
      values
      |> Enum.min_max()

    (elem(range, 1) - elem(range, 0)) / class_size
  end

  def variancia(values) do
    m = media(values)

    values
    |> Enum.map(fn x ->
      :math.pow(x - m, 2)
    end)
    |> Enum.sum()
    |> Kernel./(length(values) - 1)
  end

  def desvio_padrao(values), do: :math.sqrt(variancia(values))

  def coeficiente_de_variacao(values), do: desvio_padrao(values) / media(values)
end
