#include "tcpbox_factory.hpp"

#include "tcpbox_system.hpp"
#include "tcpbox_client.hpp"

#include"entity_manager/static_components.hpp"

namespace talorion {

  tcpbox_factory::tcpbox_factory(QObject *par) : QObject(par)
  {

  }

  tcpbox_factory &tcpbox_factory::get_instance()
  {
    // Since it's a static variable, if the class has already been created,
    // It won't be created again.
    // And it **is** thread-safe in C++11.

    static tcpbox_factory myInstance;

    // Return a reference to our instance.
    return myInstance;
  }

  tcpbox_factory::tcpbox_t tcpbox_factory::create_new_tcpbox(tcpbox_system& sys,const QString &box_name, const QString &host_name, quint16 port, qint32 box_id) const
  {
    entity_manager& mng = sys.get_entity_manager();
    tcpbox_t tcpbox=mng.create_new_entity();

    mng.create_component_and_add_to(NAME_COMPONENT, tcpbox);
    mng.create_component_and_add_to(HOST_NAME_COMPONENT, tcpbox);
    mng.create_component_and_add_to(PORT_COMPONENT, tcpbox);
    mng.create_component_and_add_to(BOX_ID_COMPONENT, tcpbox);


    mng.set_component_data_for_entity(NAME_COMPONENT,               tcpbox, box_name);
    mng.set_component_data_for_entity(HOST_NAME_COMPONENT,          tcpbox, host_name);
    mng.set_component_data_for_entity(PORT_COMPONENT,               tcpbox, port);
    mng.set_component_data_for_entity(BOX_ID_COMPONENT,             tcpbox, box_id);

    //if(mng.is_valid(tcpbox)){
    sys.add_box(tcpbox);
    //}

    return tcpbox;
  }

  tcpbox_client* tcpbox_factory::create_new_tcpbox_client(tcpbox_system& sys, tcpbox_factory::tcpbox_t tcpbox) const
  {
    tcpbox_client* client=Q_NULLPTR;
    entity_manager& mng = sys.get_entity_manager();

    if(mng.is_valid(tcpbox)){
      client=new tcpbox_client(tcpbox, sys);
    }

    //auto was_added = false;
    //if(client != Q_NULLPTR)
      auto was_added = sys.add_client(client);

    if(!was_added){
        delete client;
        client=Q_NULLPTR;
      }

    return client;
  }

} // namespace talorion
