#include <iostream>
#include <string>
using namespace std;

// دالة لقراءة درجات الحرارة وحساب مجموعها
double readTemperatures(double& sum, string daysOfWeek[]) {
    double temp;
    sum = 0;
    for (int i = 0; i < 7; i++) {
        cout << daysOfWeek[i] << ": ";
        cin >> temp;
        sum += temp;
    }
    return sum / 7.0;
}

// دالة لطباعة وصف الطقس
void describeWeather(double avgCelsius) {
    if (avgCelsius <= 0)
        cout << "Weather description: Freezing, need a jacket" << endl;
    else if (avgCelsius <= 15)
        cout << "Weather description: Cold, the jacket is nice" << endl;
    else if (avgCelsius <= 25)
        cout << "Weather description: Cool, a warm shirt is enough" << endl;
    else if (avgCelsius <= 30)
        cout << "Weather description: Warm, no need for heavy clothes" << endl;
    else if (avgCelsius <= 40)
        cout << "Weather description: Hot, a nice t-shirt is good" << endl;
    else if (avgCelsius <= 100)
        cout << "Weather description: Too hot to live in, you need an umbrella!" << endl;
    else
        cout << "Weather description: Boiling!" << endl;
}

int main() {
    char ans;
    string daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    do {
        char kindoftemp;
        double sum = 0;

        cout << "Choose temperature type ('c' for Celsius, 'f' for Fahrenheit): ";
        cin >> kindoftemp;

        kindoftemp = tolower(kindoftemp);
        if (kindoftemp != 'c' && kindoftemp != 'f') {
            cout << "Invalid input!" << endl;
            continue;
        }

        cout << "Enter the temperatures for the week:\n";
        double average = readTemperatures(sum, daysOfWeek);
        double avgCelsius, avgFahrenheit;

        if (kindoftemp == 'c') {
            avgCelsius = average;
            avgFahrenheit = (9.0 / 5.0) * avgCelsius + 32;
        } else {
            avgFahrenheit = average;
            avgCelsius = (5.0 / 9.0) * (avgFahrenheit - 32);
        }

        cout << "\n--- Weekly Average Temperature ---\n";
        cout << "Average in Celsius: " << avgCelsius << "°C" << endl;
        cout << "Average in Fahrenheit: " << avgFahrenheit << "°F" << endl;

        cout << "\n--- Weather Summary ---\n";
        describeWeather(avgCelsius);

        cout << "\nWould you like to try again? (y/Y to continue): ";
        cin >> ans;
        cout << "-----------------------------------\n";

    } while (ans == 'y' || ans == 'Y');

    cout << "\nEnjoy your time, whatever the weather, and smile 😊\n";
    return 0;
}