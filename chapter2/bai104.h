// 104.Viết chương trình nhập vào ngày, tháng, năm. Tính xem ngày đó là ngày thứ bao nhiêu trong năm.
#pragma once

int countDays(int day, int month, int year) {
    int sumDay = day;
    for (int i = 1; i < month; ++i)
    {
        switch (i)
        {
        case 2:
            sumDay += (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            sumDay += 30;
            break;

        default:
            sumDay += 31;
            break;
        }
    }
    return sumDay;
}