#include "Zombie.hpp"

int main() {
  Zombie* zombie;

  zombie = newZombie( "Alice" );
  zombie->announce();
  delete zombie;
  randomChump( "Bob" );
  return 0;
}
