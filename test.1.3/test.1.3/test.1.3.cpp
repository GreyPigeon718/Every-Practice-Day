class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> week{ "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        vector<int> month_day{ 0,31,28,31,30,31,30,31,31,30,31,30,31 };
        //1970 年 12 月 31 日是星期四，
        int days = (year - 1971) * 365 + (year - 1769) / 4;
        for (int i = 0; i < month; ++i)
            days += month_day[i];
        if (((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) && month > 2)
            days++;
        days += day;
        return week[(days + 3) % 7];
    }
};