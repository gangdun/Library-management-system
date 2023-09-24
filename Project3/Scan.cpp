#include"head.h"

int System::scan()
{
    // ����һ��zbar��ͼ��ɨ����
    ImageScanner scanner;

    // ����ɨ���������ã�ֻʶ��EAN-13���͵�������
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 0);
    scanner.set_config(ZBAR_EAN13, ZBAR_CFG_ENABLE, 1);

    // ����һ��opencv����Ƶ��׽���󣬴�Ĭ�ϵ�����ͷ
    VideoCapture cap(1);

    if (!cap.isOpened())
    {
        cout << "�޷�������ͷ" << endl;
        return -1;
    }

    namedWindow("Barcode Scanner", WINDOW_AUTOSIZE);

    while (true)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty())
        {
            cout << "�޷���ȡ��Ƶ֡" << endl;
            break;
        }

        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        int width = gray.cols;
        int height = gray.rows;
        uchar* raw = gray.data;

        // ����һ��zbar��ͼ��������ڴ洢�Ҷ�ͼ��
        Image image(width, height, "Y800", raw, width * height);

        // ʹ��ͼ��ɨ����ɨ��ͼ����󣬷���ʶ�𵽵������������
        int n = scanner.scan(image);
        String isbn;
        // ����ʶ�𵽵�������
        for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
        {
            // ��ȡ����������ͣ����ݺ�λ��
            
            string type = symbol->get_type_name();
            string data = symbol->get_data();
            vector<Point> loc;
            for (int i = 0; i < symbol->get_location_size(); i++)
            {
                loc.push_back(Point(symbol->get_location_x(i), symbol->get_location_y(i)));
            }

            // ����Ƶ֡�ϻ���������ı߿������
            polylines(frame, loc, true, Scalar(0, 255, 0), 2);
            putText(frame, data, loc[0], FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

            // ��ӡ����������ͺ����ݵ�����̨
            cout << "Barcode Type: " << type << endl;
            cout << "Barcode Data: " << data << endl;
            isbn = data;
        }
        if (isbn.size() > 0)
        {
            api_get(isbn);
            return 1;
        }
        imshow("Barcode Scanner", frame);
        /*if (flag)
        {
            break;
        }*/
        char c = (char)waitKey(10);
        if (c == 27)
        {
            scan_flag = false;
            break;
        }
    }

    cap.release();
    destroyAllWindows();

    return 0;
}