defmodule ExUmTest do
  use ExUnit.Case
  doctest ExUm

  def atrizes, do: [22, 37, 28, 63, 32, 26, 31, 27, 27, 28, 30, 26, 29, 24, 38, 25, 29, 41,
             30, 35, 35, 33, 29, 38, 54, 24, 25, 46, 41, 28, 40, 39, 29, 27, 31, 38,
             29, 25, 35, 60, 43, 35, 34, 34, 17, 37, 42, 41, 36, 32, 41, 33, 31, 74,
             33, 50, 38, 61, 21, 41, 26, 80, 42, 19, 33, 35, 45, 49, 39, 34, 26, 25,
             33, 35, 35, 28]

  def atores, do: [44, 41, 62, 52, 41, 34, 34, 52, 41, 37, 38, 34, 32, 40, 43, 56, 41, 39, 49,
            57, 41, 38, 42, 52, 51, 35, 30, 39, 41, 44, 49, 35, 47, 31, 47, 37, 57, 42,
            45, 42, 44, 62, 43, 42, 48, 49, 56, 38, 60, 30, 40, 42, 36, 76, 39, 53, 45,
            36, 62, 43, 51, 32, 42, 54, 52, 37, 38, 32, 45, 60, 46, 40, 36, 47, 29, 43]

  test "media atrizes" do
    assert ExUm.media(atrizes) == 35.4
  end

  test "mediana atrizes" do
    assert ExUm.mediana(atrizes) == 33.5
  end

  test "moda atrizes" do
    assert ExUm.moda(atrizes) == [35]
  end

  test "ponto medio atrizes" do
    assert ExUm.ponto_medio(atrizes) == 48.5
  end

  test "amplitude atrizes" do
    assert ExUm.amplitude(atrizes) == 63
  end

  test "desvio padrao atrizes" do
    assert ExUm.desvio_padrao(atrizes) == 11.36
  end

  test "variancia atrizes" do
    assert ExUm.variancia(atrizes) == 129.10
  end

  test "coeficiente atrizes" do
    assert ExUm.coeficiente_de_variacao(atrizes) == 32.09
  end
end
