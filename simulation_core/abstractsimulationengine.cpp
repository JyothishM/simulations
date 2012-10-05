#include "abstractsimulationengine.h"
#include "abstractsimulation.h"
#include "simulation_consts.h"
#include "csvreader.h"
#include <QFile>
#include <QDebug>

AbstractSimulationEngine::AbstractSimulationEngine(QObject *parent) :
    QObject(parent)
{
    bState = false;
    mSimCount = 0;
    mCurSimln=0;
}
AbstractSimulationEngine::~AbstractSimulationEngine()
{

}
void AbstractSimulationEngine::Start()
{
    bState = true;
    for(int i=0; i<mSimCount; i++)
    {
        if(!bState)
        {
            qDebug() << tr("State is false, terminating simulation.");
            break;
        }
        else
        {
            QString simlnType = FindSimulationName(i);
            mCurSimln = CreateSimulation(simlnType,i);
            if(mCurSimln)
            {
                qDebug() << tr("Simulation no %0 of type '%1' starting..! %2 % complete").arg(i+1).arg(simlnType).arg((float)(i+1)/mSimCount*100);
                if(mCurSimln->Start())
                    qDebug() << tr("Simulation no %0 of type '%1' completed").arg(i+1).arg(simlnType);
                else
                    qDebug() << tr("Error :Could not start simulation no %0 of type '%1'").arg(i+1).arg(simlnType);

                onSimulationFinished(mCurSimln);
                // deleting simulation.
                delete mCurSimln;
            }
            else
                qDebug() << tr("Could not start simulation of type '%0'").arg(simlnType);
        }
    }
    onAllSimulationEnd();
}
void AbstractSimulationEngine::StopWithCurSimulation()
{
    SetState(false);
}
bool AbstractSimulationEngine::GetState()
{
    return bState;
}
void AbstractSimulationEngine::SetState(bool state)
{
    bState = state;
}
int AbstractSimulationEngine::GetSimultionCount()
{
    return mSimCount;
}
AbstractSimulation* AbstractSimulationEngine::GetCurSimulation()
{
    return mCurSimln;
}
// static fns.
void AbstractSimulationEngine::SetSetting(int id,QString name, QString value)
{
    if(!name.isEmpty() && sSettingList.count()>id)
    {
        SettingSet settingset = sSettingList.at(id);
        settingset.insert(name,value);
        sSettingList.replace(id,settingset);
    }
}
QString AbstractSimulationEngine::GetValue(QString name,int id)
{
    if(id==-1 && mCurSimln)
        id = mCurSimln->GetSimId();

    if(sSettingList.count()>id)
        return sSettingList.at(id).value(name);

    return "";
}
bool AbstractSimulationEngine::SetSettingsFile(QString filename)
{
    return ReadSettings(filename);
}
bool AbstractSimulationEngine::ReadSettings(QString filename)
{
    sSettingList.clear();
    CSVTable table;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
         qDebug() << tr("file :%0 opening succes.").arg(filename);
         bool bCSVread = CSVreader::ReadCSV(&file,
                                            table,
                                            SETTINGS_CSV_FIELD_SAPORATOR,
                                            SETTINGS_CSV_FIELD_END);
         file.close();
         qDebug() << "file closed.";

         if(bCSVread && !table.isEmpty())
         {
            QVariantList Fieldnames = table.first();
            int count = table.count();
            for(int i=1; i<count; i++)
            {
                QVariantList simValueLine = table.at(i);
                SettingSet settingset;
                int len = qMin(simValueLine.count(),Fieldnames.count());
                for(int j=0; j<len; j++)
                {
                    settingset.insert(Fieldnames.at(j).toString().trimmed(),simValueLine.at(j).toString().trimmed());
                }
                sSettingList.append(settingset);

                // displaying setting set
                qDebug() << tr("\nSetting set no :%0").arg(i);
                foreach(QString name,settingset.keys())
                    qDebug() << QString("\t %0 = %1").arg(name).arg(settingset.value(name));
            }
            mSimCount = sSettingList.count();
         }
         else
            qDebug() << tr("file :%0 contains errors.").arg(filename);
    }
    else
        qDebug() << tr("file :%0 opening failed.").arg(filename);
}
void AbstractSimulationEngine::onSimulationFinished(AbstractSimulation* smln)
{
    //does nothing
}
void AbstractSimulationEngine::onAllSimulationEnd()
{
    //does nothing
}

QString AbstractSimulationEngine::FindSimulationName(int id)
{
    return GetValue(STR_SIMTYPE_FIELD,id);
}
