#include <MenuCommand.h>

MenuCommand::MenuCommand() : receiver(nullptr)
{
}

MenuCommand::MenuCommand(const std::string& description) : receiver(nullptr), description(description)
{
}

void MenuCommand::setReceiver(MoverController* receiver) {
  this->receiver = receiver;
}

void MenuCommand::test() {
  this->criterio->acepta(this->receiver);
}

std::string MenuCommand::getDescription() {
  return description;
}

MenuCommand::~MenuCommand()
{
}
