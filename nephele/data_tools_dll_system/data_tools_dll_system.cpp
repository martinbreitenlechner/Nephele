#include "data_tools_dll_system.hpp"

#include "dtd_config_widget/dtd_config_widget.hpp"

#include "core/event_manager.hpp"

namespace talorion {

    data_tools_dll_system::data_tools_dll_system(QObject *par) :
        QThread(par),
        abstract_system("{41dc1dd5-2b1f-4424-8203-7b887c78e437}"),
        config_wdg(NULL)
    {
        config_wdg =  new dtd_config_widget();

        connect(event_manager::get_instance(),SIGNAL(application_aboutToQuit()),this,SLOT(quit()));
    }

    data_tools_dll_system::~data_tools_dll_system()
    {
        delete config_wdg;
    }

    void data_tools_dll_system::run()
    {
        exec();
    }

    void data_tools_dll_system::do_start_system()
    {
        this->start();
    }

    abstract_configuration_widget *data_tools_dll_system::do_get_configuration_widget()
    {
        return config_wdg;
    }

} // namespace talorion

