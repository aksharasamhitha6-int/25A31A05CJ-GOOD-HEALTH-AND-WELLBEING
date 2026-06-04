#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class HealthMonitor
{
    string medicine;
    int hour, minute;
    float weight;
    int systolic, diastolic;

public:
    void getData()
    {
        cout << "Enter Medicine Name: ";
        cin >> medicine;

        cout << "Enter Medicine Time (HH MM): ";
        cin >> hour >> minute;

        cout << "Enter Weight (kg): ";
        cin >> weight;

        cout << "Enter Blood Pressure (Systolic Diastolic): ";
        cin >> systolic >> diastolic;
    }

    void display()
    {
        cout << "\n----- Health Record -----\n";
        cout << "Medicine Name : " << medicine << endl;
        cout << "Medicine Time : " << hour << ":" << minute << endl;
        cout << "Weight        : " << weight << " kg" << endl;
        cout << "Blood Pressure: "
             << systolic << "/" << diastolic << " mmHg" << endl;
    }

    void checkReminder()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int currentHour = ltm->tm_hour;
        int currentMinute = ltm->tm_min;

        cout << "\nCurrent Time : "
             << currentHour << ":" << currentMinute << endl;

        if(currentHour == hour &&
           currentMinute == minute)
        {
            cout << "\n*** MEDICINE ALERT ***" << endl;
            cout << "Time to take " << medicine << endl;
        }
        else
        {
            cout << "\nMedicine time not reached." << endl;
        }
    }
};

int main()
{
    HealthMonitor patient;

    patient.getData();
    patient.display();
    patient.checkReminder();

    return 0;
}