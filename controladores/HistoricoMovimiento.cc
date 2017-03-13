#include <HistoricoMovimiento.h>

HistoricoMovimiento::HistoricoMovimiento()
{
}

void HistoricoMovimiento::insertMovimiento(CriterioMovimiento* criterio)
{
  undoStack.push(criterio->clone());

  while(not redoStack.empty()) {
    CriterioMovimiento *borrado = redoStack.top();
    redoStack.pop();
    delete borrado;
  }
}

void HistoricoMovimiento::undo()
{
  if (not undoStack.empty())
    {
      CriterioMovimiento* criterio = undoStack.top();
      undoStack.pop();
      criterio->undoMovimiento();
      redoStack.push(criterio);
    }
}

void HistoricoMovimiento::redo()
{
  if (not redoStack.empty())
    {
      CriterioMovimiento* criterio = redoStack.top();
      redoStack.pop();
      criterio->doMovimiento();
      undoStack.push(criterio);
    }
}

HistoricoMovimiento::~HistoricoMovimiento()
{
  CriterioMovimiento *borrado;
  while(not undoStack.empty()) {
    borrado = undoStack.top();
    undoStack.pop();
    delete borrado;
  }

  while(not redoStack.empty()) {
    borrado = redoStack.top();
    redoStack.pop();
    delete borrado;
  }
}
