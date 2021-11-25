defmodule ExUm do
  require Integer
  require Decimal

  def media(numbers) do
    if length(numbers) == 0 do
      0
    else
      Enum.sum(numbers) / length(numbers)
      |> Decimal.from_float()
      |> Decimal.round(1)
      |> Decimal.to_float()
    end
  end

  def mediana(numbers) do
    sorted = Enum.sort(numbers)
    size = length(sorted)
    if Integer.is_odd(size) do
      sorted[size / 2]
    else
      media([Enum.at(sorted, trunc(size / 2 - 1)), Enum.at(sorted, trunc(size / 2))])
    end
  end

  def moda(numbers) do
    numbers
    |> Enum.frequencies()
    |> Enum.max_by(fn {_number, count} -> count end)
    |> elem(0)
  end

end
