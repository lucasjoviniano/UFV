atores = [
  44,41,62,52,41,34,34,52,41,37,38,34,32,40,43,56,41,39,49,57,41,38,42,52,51,35,30,39,41,44,49,35,47,31,47,37,57,42,45,42,44,62,43,42,48,49,56,38,60,30,40,42,36,76,39,53,45,36,62,43,51,32,42,54,52,37,38,32,45,60,46,40,36,47,29,43
]

IO.inspect(ListaUm.media(atores), [label: "media"])
IO.inspect(ListaUm.mediana(atores), [label: "mediana"])
IO.inspect(ListaUm.moda(atores), [label: "moda", charlists: :as_lists])
IO.inspect(ListaUm.ponto_medio(atores), [label: "ponto médio"])
IO.inspect(ListaUm.amplitude(atores), [label: "amplitude"])
IO.inspect(ListaUm.desvio_padrao(atores), [label: "desvio padrão"])
IO.inspect(ListaUm.variancia(atores), [label: "variância"])
IO.inspect(ListaUm.coeficiente_de_variacao(atores), [label: "coeficiente de variação"])

IO.inspect(ListaUm.amplitude(atores, 6), [label: "amplitude de classe"])
