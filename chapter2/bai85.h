// 85. Nhập vào tháng của một năm. Cho biết tháng thuộc químấy trong năm.

#pragma once

int checkQuarter(int n)
{
    int q = 0;
    switch (n) {
    case 1:
    case 2:
    case 3:
        q = 1;
        break;
    case 4:
    case 5:
    case 6:
        q = 2;
        break;
    case 7:
    case 8:
    case 9:
        q = 3;
        break;
    case 10:
    case 11:
    case 12:
        q = 4;
        break;
    default:
        q = -1;

    }

    return q;
}