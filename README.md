# c-date-time-calculator

C program to add days to a date (with leap year handling) and seconds to a time.

## Features

- Add any number of days to a date (month and year changes are handled automatically)
- Leap year detection (divisible by 4, except centuries, unless divisible by 400)
- Add any number of seconds to a time (overflow into minutes, hours and back to 0 after 23:59:59)

## How it works

**Date:** The entered days are added to the day. While the day is larger than the length of the current month, that month's length is subtracted and the month is increased. After December, the year is increased.

**Time:** The entered seconds are added to the seconds. Overflow is passed upwards with `/` and the remainder is kept with `%` (seconds → minutes → hours). Hours are limited to 0–23.

## Example

```
Start date: 29.2.2024
Enter a number to add to the date
12
The new date is 12.3.2024
```
