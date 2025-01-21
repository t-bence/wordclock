#include <LocalTime.h>

// Define the time change rules and timezone
TimeChangeRule myDST = {"CEST", Last, Sun, Mar, 2, 120}; // Daylight time = UTC + 2 hours
TimeChangeRule mySTD = {"CET", Last, Sun, Oct, 3, 60};   // Standard time = UTC + 1 hours
Timezone hunTZ(myDST, mySTD);

LocalTime getLocalTime(long utcTime)
{
    // Get the current UTC time from the RTC
    time_t utc = static_cast<time_t>(utcTime);

    // Convert UTC time to local time
    time_t local = hunTZ.toLocal(utc);

    // add 2.5 minutes to "center" the range
    local += TWO_HALF_MINUTES;

    // return hour between 0-11
    int intHour = hour(local) % 12;

    return {intHour, minute(local)};
}