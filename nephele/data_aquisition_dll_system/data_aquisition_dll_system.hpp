#ifndef TALORION_DATA_AQUISITION_SYSTEM_HPP
#define TALORION_DATA_AQUISITION_SYSTEM_HPP

#include<QObject>
#include<QThread>

#include "core/abstract_system.hpp"

namespace talorion {

    class data_aquisition_dll_system : public QThread, public abstract_system
    {
        Q_OBJECT
    public:
        explicit data_aquisition_dll_system(QObject *par = 0);
        ~data_aquisition_dll_system();
        Q_DISABLE_COPY(data_aquisition_dll_system)

        // QThread interface
    protected:
        virtual void run() Q_DECL_OVERRIDE;

        // abstract_system interface
    private:
        virtual void do_start_system() Q_DECL_OVERRIDE;
    };

} // namespace talorion

#endif // TALORION_DATA_AQUISITION_SYSTEM_HPP
