#ifndef PARTIDAKLONDIKE_H
#define PARTIDAKLONDIKE_H

#include <Mazo.h>
#include <memory>

const int MAX_RANKING = 10;
typedef std::vector<MazoPointer> MazoList;

class PartidaKlondike
{
  public:
  enum Estado
  {
    INICIAL,
    EN_CURSO,
    EN_CURSO_AUTOMATICO,
    FINAL,
    SALIR
  };

  PartidaKlondike();
  PartidaKlondike(const PartidaKlondike& partida);
  ~PartidaKlondike();

  void addTableau(const MazoPointer tableau);
  void addFundacion(const MazoPointer fundacion);
  void addStock(const MazoPointer stock);
  void addDescartes(const MazoPointer descartes);
  void deletePartida();
  void incMarcador(int puntuacion);
  bool comprobarVictoria();

  int getEstado() const;
  const MazoList getFundaciones() const { return fundaciones; };
  const MazoList getTableaus() const { return tableaus; };
  const MazoPointer getDescartes() const { return descartes; };
  const MazoPointer getStock() const { return stock; };

  MazoPointer getFundacion(int fundacion);
  int getNumFundaciones();
  MazoPointer getTableau(int tableau);
  int getNumTableaus();

  const int getTipoPartida() const { return tipoPartida; };
  const int getMarcador() { return marcador; };
  const int getMinimo() { return minimo; };
  const std::string getNombreRanking(int pos) { return ranking[pos].first; };
  const int getPuntuacionRanking(int pos) { return ranking[pos].second; };

  void setMarcador(int puntuacion) { marcador = puntuacion; };
  void setMinimo(int puntuacion) { minimo = puntuacion; };
  void setEstado(PartidaKlondike::Estado estado);
  void setTipoPartida(const int tipo) { tipoPartida = tipo; };
  void setNombreRanking(int pos, std::string nombre) { ranking[pos].first = nombre; };
  void setPuntuacionRanking(int pos, int valor) { ranking[pos].second = valor; };

 protected:

 private:
  bool tableausVacios();

  Estado estado;
  int tipoPartida;
  int marcador;
  int minimo;
  std::vector<MazoPointer> fundaciones;
  std::vector<MazoPointer> tableaus;
  MazoPointer descartes;
  MazoPointer stock;
  std::pair <std::string, int> ranking[MAX_RANKING];
};

#endif
