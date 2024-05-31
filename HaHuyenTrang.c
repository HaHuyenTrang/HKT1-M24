#include <stdio.h>
#include <string.h>

struct DiemSinhVien {
    int MaSo;
    char HoTen[20];
    float Diem;
};

struct BangDiem {
    struct DiemSinhVien A[100];
    int ts;
};

void themDiemSV(struct BangDiem *mark) {
    int n;
    printf("Nhap so luong diem sinh vien can them: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien %d:\n", i + 1);
        printf("Ma so: ");
        scanf("%d", &mark->A[mark->ts].MaSo);
        printf("Ho ten: ");
        scanf(" %[^\n]s", mark->A[mark->ts].HoTen);
        printf("Diem: ");
        scanf("%f", &mark->A[mark->ts].Diem);
        mark->ts++;
    }
    printf("Da them %d diem sinh vien.\n", n);
}

void suaDiemTheoHoTen(struct BangDiem *mark) {
    char tenSV[50];
    printf("Nhap ho ten sinh vien can sua diem: ");
    scanf(" %[^\n]s", tenSV);
    for (int i = 0; i < mark->ts; i++) {
        if (strcmp(mark->A[i].HoTen, tenSV) == 0) {
            printf("Nhap diem moi cho sinh vien %s: ", mark->A[i].HoTen);
            scanf("%f", &mark->A[i].Diem);
            printf("Da sua diem sinh vien %s.\n", mark->A[i].HoTen);
            return;
        }
    }
    printf("Khong tim thay sinh vien co ten %s.\n", tenSV);
}

void sapXepBangDiem(struct BangDiem *mark) {
    for (int i = 0; i < mark->ts - 1; i++) {
        for (int j = 0; j < mark->ts - i - 1; j++) {
            if (mark->A[j].Diem < mark->A[j + 1].Diem) {
                struct DiemSinhVien temp = mark->A[j];
                mark->A[j] = mark->A[j + 1];
                mark->A[j + 1] = temp;
            }
        }
    }
    printf("Danh sach diem sinh vien:\n");
    printf("%-10s %-30s %-10s\n", "Ma so", "Ho ten", "Diem");
    for (int i = 0; i < mark->ts; i++) {
        printf("%-10d %-30s %.2f\n", mark->A[i].MaSo, mark->A[i].HoTen, mark->A[i].Diem);
    }
}

int menu() {
    int choice;
    printf("Chon chuc nang (1-3, 0 de thoat): ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    struct BangDiem mark = {0};
    int choice;
    while (1) {
        choice = menu();
        if (choice == 0) {
            printf("Thoat chuong trinh.\n");
            break;
        } else if (choice == 1) {
            themDiemSV(&mark);
        } else if (choice == 2) {
            suaDiemTheoHoTen(&mark);
        } else if (choice == 3) {
            sapXepBangDiem(&mark);
        } else {
            printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }
    return 0;
}
