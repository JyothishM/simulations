#ifndef ABSTRACTSIMULATIONENGINE_H
#define ABSTRACTSIMULATIONENGINE_H

#include "simulation_core_global.h"
#include <QObject>
#include <QHash>

typedef QHash<QString,QString> SettingSet;


class AbstractSimulation;

class SIMULATION_CORESHARED_EXPORT AbstractSimulationEngine : public QObject
{
    Q_OBJECT
public:
    explicit AbstractSimulationEngine(QObject *parent = 0);
    virtual ~AbstractSimulationEngine();
    virtual AbstractSimulation* CreateSimulation(QString type,int id)=0;
    void Start();
    void StopWithCurSimulation();
    bool GetState();
    void SetState(bool state);
    int GetSimultionCount();
    AbstractSimulation* GetCurSimulation();

    // static fns.
    void SetSetting(int id,QString name,QString value);
    QString GetValue(QString name, int id=-1);   // -1 is current simulation
    bool SetSettingsFile(QString filename);
protected:
    virtual bool ReadSettings(QString filename);
protected slots:
    virtual void onSimulationFinished(AbstractSimulation* smln);
    virtual void onAllSimulationEnd();
private:
    QString FindSimulationName(int id);

    bool bState;
    int mSimCount;
    AbstractSimulation* mCurSimln;
    QList<SettingSet> sSettingList;
};

#endif // ABSTRACTSIMULATIONENGINE_H
