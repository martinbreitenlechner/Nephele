#include "undefined_state.hpp"

#include "initialized_state.hpp"

namespace talorion {

  undefined_state::undefined_state(QObject *par)
    : abstract_system_state(par)
  {

  }

  undefined_state::~undefined_state()
  {

  }

  abstract_system_state *undefined_state::state_transition(abstract_system *sys, abstract_system::state_input_t input)
  {
    Q_UNUSED(sys);
    if(input == abstract_system::SYSTEM_INPUT_INITIALIZE){
        //sys->do_initialize();
        return new initialized_state();
      }

    // Stay in this state.
    return NULL;
  }

} // namespace talorion
