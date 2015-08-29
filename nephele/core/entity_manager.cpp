#include "entity_manager.hpp"

#include <QAtomicPointer>
#include <QMutex>
#include <QDebug>
#include <QSignalMapper>

#include "core/event_manager.hpp"
#include "analogvalue.hpp"



namespace talorion {

    QAtomicPointer<entity_manager> entity_manager::_instance;
    QMutex entity_manager::_mutex;

    entity_manager::entity_manager(QObject *par) :
        QObject(par),
        analog_values(),
        act_value_signalMapper(NULL),
        set_value_signalMapper(NULL)
    {
        act_value_signalMapper = new QSignalMapper(this);
        set_value_signalMapper = new QSignalMapper(this);
        connect(act_value_signalMapper, SIGNAL(mapped(int)), event_manager::get_instance(), SIGNAL(act_value_changed(int)));
        connect(set_value_signalMapper, SIGNAL(mapped(int)), event_manager::get_instance(), SIGNAL(set_value_changed(int)));
    }

    entity_manager::~entity_manager()
    {
    }

    entity_manager* entity_manager::get_instance()
    {
        if ( !_instance ){
            _mutex.lock();
            if (!_instance)
                _instance = new entity_manager();
            _mutex.unlock();
        }
        return _instance;
    }//end getInstance

    void entity_manager::destroy()
    {
        _mutex.lock();
        if ( _instance )
            delete _instance;
        _instance = 0;
        _mutex.unlock();
    }

    analogValue* entity_manager::createNewAnalogValue(QString nameVal, QString unitsVal, double smin, double smax, double amin, double amax, double setVal, int id, int box_id)
    {
        int hash = generate_Hash(box_id, id);
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            fc = new analogValue(nameVal,
                                 unitsVal,
                                 smin,
                                 smax,
                                 amin,
                                 amax,
                                 setVal,
                                 id,
                                 box_id,
                                 hash
                                 );
            analog_values.insert(hash,fc);
            connect(fc, SIGNAL(act_value_changed()), act_value_signalMapper, SLOT(map()));
            act_value_signalMapper->setMapping(fc, hash);
            connect(fc, SIGNAL(set_value_changed()), set_value_signalMapper, SLOT(map()));
            set_value_signalMapper->setMapping(fc, hash);
        }

        return fc;
    }

    QString entity_manager::get_name_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return "";
        }
        return fc->getName();
    }

    QString entity_manager::get_units_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return "";
        }
        return fc->getUnits();
    }

    void entity_manager::set_actValue_component(int hash, double val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            fc->setAct(val);
        }
    }

    void entity_manager::set_setValue_component(int hash, double val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            fc->setSet(val);
        }
    }

    void entity_manager::set_setMin_component(int hash, double val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            Q_UNUSED(val);
        }
    }

    void entity_manager::set_setMax_component(int hash, double val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            Q_UNUSED(val);
        }
    }

    void entity_manager::set_actMin_component(int hash, double val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            Q_UNUSED(val);
        }
    }

    void entity_manager::set_actMax_component(int hash, double val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            Q_UNUSED(val);
        }
    }

    void entity_manager::set_name_component(int hash, QString val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            Q_UNUSED(val);
        }
    }

    void entity_manager::set_units_component(int hash, QString val)
    {
        analogValue* fc =get_analogValue(hash);
        if (fc){
            Q_UNUSED(val);
        }
    }

    double entity_manager::get_actValue_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return -1;
        }
        return fc->getAct();
    }

    double entity_manager::get_setValue_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return -1;
        }
        return fc->getSet();
    }

    double entity_manager::get_setMin_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return -1;
        }
        return fc->getSmin();
    }

    double entity_manager::get_setMax_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return -1;
        }
        return fc->getSmax();
    }

    double entity_manager::get_actMin_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return -1;
        }
        return fc->getAmin();
    }

    double entity_manager::get_actMax_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return -1;
        }
        return fc->getAmax();
    }

    int entity_manager::get_id_component(int hash) const
    {
        analogValue* fc =get_analogValue(hash);
        if (!fc){
            return -1;
        }
        return fc->getId();
    }

    analogValue *entity_manager::get_analogValue(int hash) const
    {
        //qDebug() << hash;
        QMap<int, analogValue*>::ConstIterator av = analog_values.constFind(hash);
        if (av == analog_values.constEnd()){
            return NULL;
        }
        return av.value();
    }

    int entity_manager::generate_Hash(int box_id, int value_id) const
    {
        return (box_id*P1 + value_id)*P2;
    }


} // namespace talorion

