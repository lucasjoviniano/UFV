defmodule ListaUmTest do
  use ExUnit.Case
  doctest ListaUm

  @atrizes [
    22,
    37,
    28,
    63,
    32,
    26,
    31,
    27,
    27,
    28,
    30,
    26,
    29,
    24,
    38,
    25,
    29,
    41,
    30,
    35,
    35,
    33,
    29,
    38,
    54,
    24,
    25,
    46,
    41,
    28,
    40,
    39,
    29,
    27,
    31,
    38,
    29,
    25,
    35,
    60,
    43,
    35,
    34,
    34,
    17,
    37,
    42,
    41,
    36,
    32,
    41,
    33,
    31,
    74,
    33,
    50,
    38,
    61,
    21,
    41,
    26,
    80,
    42,
    19,
    33,
    35,
    45,
    49,
    39,
    34,
    26,
    25,
    33,
    35,
    35,
    28
  ]

  test "media simples" do
    assert ListaUm.media([1, 2, 3, 4]) == 2.5
  end

  test "media atrizes" do
    assert_in_delta(ListaUm.media(@atrizes), 35.4, 0.09)
  end

  test "media decimais" do
    assert_in_delta(ListaUm.media([5.40, 1.10, 0.42, 0.73, 0.48, 1.10]), 1.538, 0.0009)
  end

  test "mediana impar" do
    assert ListaUm.mediana([1, 2, 3, 4, 5]) == 3
  end

  test "mediana par" do
    assert ListaUm.mediana([1.83, 1.87, 1.97, 1.99, 2.01, 2.05]) == 1.98
  end

  test "mediana atrizes" do
    assert ListaUm.mediana(@atrizes) == 33.5
  end

  test "moda unica" do
    assert ListaUm.moda([5.40, 1.10, 0.42, 0.73, 0.48, 1.10]) == [1.10]
  end

  test "bimodal" do
    assert ListaUm.moda([27, 27, 27, 55, 55, 55, 88, 88]) == [27, 55]
  end

  test "moda atrizes" do
    assert ListaUm.moda(@atrizes) == [35]
  end

  test "ponto medio" do
    assert ListaUm.ponto_medio([5.40, 1.10, 0.42, 0.73, 0.48, 1.10]) == 2.91
  end

  test "ponto medio atrizes" do
    assert ListaUm.ponto_medio(@atrizes) == 48.5
  end

  test "amplitudes iguais" do
    assert ListaUm.amplitude([6, 6, 6]) == 0
  end

  test "amplitude pequena" do
    assert ListaUm.amplitude([4, 7, 7]) == 3
  end

  test "amplitude alta" do
    assert ListaUm.amplitude([1, 3, 14]) == 13
  end

  test "amplitude atrizes" do
    assert ListaUm.amplitude(@atrizes) == 63
  end

  test "variancia 1" do
    assert_in_delta(ListaUm.variancia([5, 8, 10, 7]), 4.333, 0.0009)
  end

  test "variancia 2" do
    assert_in_delta(ListaUm.variancia([8, 6, 6, 12]), 8, 0.0009)
  end

  test "variancia 3" do
    assert_in_delta(ListaUm.variancia([11, 9, 5, 10]), 6.916, 0.0009)
  end

  test "variancia atrizes" do
    assert_in_delta(ListaUm.variancia(@atrizes), 129.10, 0.09)
  end

  test "desvio padrao" do
    assert_in_delta(ListaUm.desvio_padrao([6, 6, 6]), 0, 0.0009)
  end

  test "desvio padrao 2" do
    assert_in_delta(ListaUm.desvio_padrao([1, 3, 14]), 7, 0.0009)
  end

  test "desvio padrao 3" do
    assert_in_delta(ListaUm.desvio_padrao([4, 4, 7]), 1.732, 0.0009)
  end

  test "desvio padrao atrizes" do
    assert_in_delta(ListaUm.desvio_padrao(@atrizes), 11.36, 0.009)
  end

  test "coeficiente de variação" do
    assert_in_delta(ListaUm.coeficiente_de_variacao([4, 4, 7]), 0.346, 0.0009)
  end

  test "coeficiente de variação atrizes" do
    assert_in_delta(ListaUm.coeficiente_de_variacao(@atrizes), 0.3208, 0.00009)
  end
end
