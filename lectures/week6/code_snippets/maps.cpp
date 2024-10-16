#include <iostream>
#include <map>

enum ParticleType {
  planet,
  star,
  atom,
};

int main() {
  std::map<std::string, ParticleType> particle_types;

  particle_types["mars"] = planet;
  particle_types["sun"] = star;
  particle_types["copper"] = atom;

  std::map<std::string, ParticleType>::iterator it = particle_types.begin();
  std::map<std::string, ParticleType>::iterator end = particle_types.end();

  for (; it != end; ++it) {
    std::string key = it->first;
    ParticleType p_type = it->second;

    std::cout << "key:" << key << " -> ";
    std::cout << p_type << std::endl;
  }
}