defmodule ExUm do
  require Integer
  require Decimal

  def media([]), do: 0
  def media(numbers) do
    Enum.sum(numbers) / length(numbers)
    |> Decimal.from_float()
    |> Decimal.round(1)
    |> Decimal.to_float()
  end

  def mediana(numbers) do
    sorted = Enum.sort(numbers)
    size = length(sorted)
    if Integer.is_odd(size) do
      sorted[trunc(size / 2)]
    else
      media([Enum.at(sorted, trunc(size / 2 - 1)), Enum.at(sorted, trunc(size / 2))])
    end
  end

  # Não serve pois só retorna uma moda, e um conjunto de dados pode ser multimodal
  # def moda(numbers) do
  #   numbers
  #   |> Enum.frequencies()
  #   |> Enum.max_by(fn {_number, count} -> count end)
  #   |> elem(0)
  # end

  def moda(numbers) do
    numbers
    |> Enum.frequencies()
    |> Enum.group_by(&elem(&1, 1))
    |> Enum.max()
    |> elem(1)
    |> Enum.map(&(elem(&1, 0)))
  end

  def ponto_medio(numbers) do
    (Enum.max(numbers) + Enum.min(numbers)) / 2
    |> Decimal.from_float()
    |> Decimal.round(1)
    |> Decimal.to_float()
  end

  @spec amplitude(list) :: number
  def amplitude(numbers), do: Enum.max(numbers) - Enum.min(numbers)

  @spec desvio_padrao(list) :: number
  def desvio_padrao(numbers) do
    :math.sqrt(variancia(numbers))
    |> Decimal.from_float()
    |> Decimal.round(2)
    |> Decimal.to_float()
  end

  def variancia(numbers) do
    m = media(numbers)
    numbers
    |> Enum.map(&(:math.pow(&1 - m, 2)))
    |> Enum.sum()
    |> Kernel./(length(numbers) - 1)
    |> Decimal.from_float()
    |> Decimal.round(2)
    |> Decimal.to_float()
  end

  def coeficiente_de_variacao(numbers) do
    (desvio_padrao(numbers) / media(numbers)) * 100
    |> Decimal.from_float()
    |> Decimal.round(2)
    |> Decimal.to_float()
  end
end
