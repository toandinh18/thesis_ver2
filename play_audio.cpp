#include "play_audio.h"
#include <QDebug>
#include <first_page.h>


play_audio::play_audio()
{

}

void play_audio::run(){
    qDebug() << "loading thread ok";
    switch(i) {
        case 0: system("cvlc --play-and-exit /home/pi/Downloads/Chao/LoiChao1.m4a /home/pi/Downloads/Chao/LoiChao2.m4a");
                qDebug() << "loading thread 0";
                break;
        case 1: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/ChatLuongGiaoTrinh.m4a");
                qDebug() << "loading thread 1";
                break;
        case 2: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/KhuVucTuHoc.m4a");
                qDebug() << "loading thread 2";
                break;
        case 3: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/NhaVeSinh.m4a");
                qDebug() << "loading thread 1";
                break;
        case 4: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/NhaXe.m4a");
                qDebug() << "loading thread 2";
                break;
        case 5: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/PhanHoi.m4a");
                qDebug() << "loading thread 1";
                break;
        case 6: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/Phonghoc.m4a");
                qDebug() << "loading thread 2";
                break;
        case 7: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/PhongThiNghiem.m4a");
                qDebug() << "loading thread 1";
                break;
        case 8: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/TaiLieuDayDu.m4a");
                qDebug() << "loading thread 2";
                break;
        case 9: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/ThoiGianDKMH.m4a");
                qDebug() << "loading thread 1";
                break;
        case 10: system("cvlc --play-and-exit /home/pi/Downloads/Hoctap/TrangWeb.m4a");
                qDebug() << "loading thread 2";
                break;
        case 20: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/DichVuCanteen.m4a");
                qDebug() << "loading thread 0";
                break;
        case 21: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/DichVuInBangDiem.m4a");
                qDebug() << "loading thread 1";
                break;
        case 22: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/DichVuNuocUong.m4a");
                qDebug() << "loading thread 2";
                break;
        case 23: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/QuyTrinhTraMuonSach.m4a");
                qDebug() << "loading thread 1";
                break;
        case 24: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/SuTienNghi.m4a");
                qDebug() << "loading thread 2";
                break;
        case 25: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/ThaiDoNhanVien.m4a");
                qDebug() << "loading thread 1";
                break;
        case 26: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/ThaiDoNhanVienCanteen.m4a");
                qDebug() << "loading thread 2";
                break;
        case 27: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/ThaiDoPhucVu.m4a");
                qDebug() << "loading thread 1";
                break;
        case 28: system("cvlc --play-and-exit /home/pi/Downloads/Dichvu/TratTuThuVien.m4a");
                qDebug() << "loading thread 2";
                break;
        case 30: system("cvlc --play-and-exit /home/pi/Downloads/Hoatdong/BoIch.m4a");
                qDebug() << "loading thread 0";
                break;
        case 31: system("cvlc --play-and-exit /home/pi/Downloads/Hoatdong/CapNhatCTXH.m4a");
                qDebug() << "loading thread 1";
                break;
        case 32: system("cvlc --play-and-exit /home/pi/Downloads/Hoatdong/DamBaoCTXH.m4a");
                qDebug() << "loading thread 2";
                break;
        case 33: system("cvlc --play-and-exit /home/pi/Downloads/Hoatdong/ToChucThuongXuyenPT.m4a");
                qDebug() << "loading thread 1";
                break;
        case 34: system("cvlc --play-and-exit /home/pi/Downloads/Hoatdong/ToChucThuongXuyen.m4a");
                qDebug() << "loading thread 2";
                break;
        default: qDebug() << "loading thread default";
                break;
    }
    qDebug() << "finish";
}
