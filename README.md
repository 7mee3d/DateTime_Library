# 📅 LibDate: C++ Date Utility Library

`LibDate.h` is a powerful C++ header-only library designed to handle a wide range of **date and calendar operations**, including calculating day differences, leap years, weekdays, and formatting dates with ease.

---

## ✅ Key Features

- 🗓️ Leap year detection.
- 📆 Calculate total days, hours, minutes, or seconds in months and years.
- ➕ Easily add days, weeks, months, or years to a date.
- ➖ Subtract time periods from a date (e.g., go back one month).
- 📅 Print full calendars for a month or year.
- 🔄 Compare two dates: is one before, after, or equal to another?
- 🧠 Work with date periods (start/end date) and calculate overlaps.
- 🔤 Format dates using custom string templates (`dd/mm/yyyy`, `Month dd yyyy`, etc.)
- 💼 Recognize business days and weekends.

---

## 📦 Library Contents

### 🧾 Enumerations

- `enDayOfWeek`: Enum for days from Sunday to Saturday.
- `enMounth`: Enum for months from January to December.
- `enCompareTwoDate`: Enum to compare two dates (`BEFORE`, `EQUAL`, `AFTER`).

### 📌 Structures

- `stDateInformation`: Represents a date (day, month, year).
- `stPeriodOfDate`: Represents a time period between two dates.

---

## 🛠️ Key Functions

### ✅ Date Validation & Basic Calculations

- `bool isLeapYear(int year)`
- `int numberOfDayInYear(int year)`
- `int numberOfDayInMonth(int year, int month)`

### ⏳ Time Unit Calculations

- `calcNumberOfHourInYear`, `calcNumberOfMinutsInYear`, `calcNumberOfSecoundsInYear`
- `calcNumberOfHourInMonth`, `calcNumberOfMinutsInMonth`, `calcNumberOfSecoundsInMonth`

### ➕ Date Increment Functions

- `increasingDayByOne`
- `increasingXWeek`, `increasingOneMonth`, `increasingXMonth`
- `increasingXYear`, `increasingOneDecade`, `increasingOneCentury`, `increasingOneMillennium`

### ➖ Date Decrement Functions

- `decreasingDayByOne`
- `decreasingWeekX`, `decreasingOneMonth`, `decreasingMonthX`
- `decreasingYearX`, `decreasingOneDecade`, `decreasingOneMilleninum`

### 📅 Calendar Printing

- `printCalenderOfMonth(year, month)`
- `printAllMonthCalenderAccordingYear(year)`

### 🧠 Comparison & Logic

- `cheakDateOneLessThanDateTwo`
- `IsDate1EqualDate2`
- `Date1AfterDate2`
- `compareTwoDates`
- `isOverLapTwoDate`
- `isDateWithinPeriod`

### 🧾 Input/Output & Formatting

- `printDateFormat(date, separator)`
- `replaseDatekDAY_kMONTH_kYEAR_FormatDate(date, format)`
- `convertRecordToLine(date)`
- `splitDateInformation(string date)`
- `fillDateInformation(vector<string>)`

### 📆 Weekday and Month Name Utilities

- `findTheOrderOfDayInWeek`
- `findDayOfWeekString(index, fullName)`
- `findNameMounthString(index, fullName)`

### 📉 Date Differences

- `calcDifferanceBetweenTwoDate`
- `vacationDays(date1, date2)`
- `dayUntilEndOfWeek`, `dayUntilEndOfMonth`, `dayUntilEndOfYear`

---

## 🔤 Supported Date Format Examples

```cpp
replaseDatekDAY_kMONTH_kYEAR_FormatDate(date, "dd/mm/yyyy")
replaseDatekDAY_kMONTH_kYEAR_FormatDate(date, "DDDD, dd Month yyyy")
replaseDatekDAY_kMONTH_kYEAR_FormatDate(date, "dd-MMM-yy")
```

---
# 👨💻 Author

**Ahmed Jehad Ahmed**  


🔗 [GitHub Profile](https://github.com/7mee3d)

📧 [Email Contact](mailto:enginnerahemdjehad2004@gmail.com)
