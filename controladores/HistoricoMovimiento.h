#ifndef HISTORICOMOVIMIENTO_H
#define HISTORICOMOVIMIENTO_H

#include <stack>
#include <CriterioMovimiento.h>

class HistoricoMovimiento
{
 public:
  HistoricoMovimiento();
  void insertMovimiento(CriterioMovimiento* criterio);
  void undo();
  void redo();
  ~HistoricoMovimiento();

 private:
  std::stack<CriterioMovimiento*> undoStack;
  std::stack<CriterioMovimiento*> redoStack;
};
#endif
