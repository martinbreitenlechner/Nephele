#ifndef ABSTRACT_SIMULATED_BOX_HPP
#define ABSTRACT_SIMULATED_BOX_HPP

#include <QObject>

class abstract_simulated_box : public QObject
{
    Q_OBJECT
public:
    explicit abstract_simulated_box(QObject *par = 0);
    virtual ~abstract_simulated_box();
    Q_DISABLE_COPY(abstract_simulated_box)

    virtual void set(int id, double val) =0;

    virtual QString getAll_json() =0;

signals:

public slots:
};

#endif // ABSTRACT_SIMULATED_BOX_HPP
