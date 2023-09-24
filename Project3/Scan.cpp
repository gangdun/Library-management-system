#include"head.h"

int System::scan()
{
    // 创建一个zbar的图像扫描器
    ImageScanner scanner;

    // 设置扫描器的配置，只识别EAN-13类型的条形码
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 0);
    scanner.set_config(ZBAR_EAN13, ZBAR_CFG_ENABLE, 1);

    // 创建一个opencv的视频捕捉对象，打开默认的摄像头
    VideoCapture cap(1);

    if (!cap.isOpened())
    {
        cout << "无法打开摄像头" << endl;
        return -1;
    }

    namedWindow("Barcode Scanner", WINDOW_AUTOSIZE);

    while (true)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty())
        {
            cout << "无法读取视频帧" << endl;
            break;
        }

        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        int width = gray.cols;
        int height = gray.rows;
        uchar* raw = gray.data;

        // 创建一个zbar的图像对象，用于存储灰度图像
        Image image(width, height, "Y800", raw, width * height);

        // 使用图像扫描器扫描图像对象，返回识别到的条形码的数量
        int n = scanner.scan(image);
        String isbn;
        // 遍历识别到的条形码
        for (Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol)
        {
            // 获取条形码的类型，内容和位置
            
            string type = symbol->get_type_name();
            string data = symbol->get_data();
            vector<Point> loc;
            for (int i = 0; i < symbol->get_location_size(); i++)
            {
                loc.push_back(Point(symbol->get_location_x(i), symbol->get_location_y(i)));
            }

            // 在视频帧上绘制条形码的边框和内容
            polylines(frame, loc, true, Scalar(0, 255, 0), 2);
            putText(frame, data, loc[0], FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 0), 2);

            // 打印条形码的类型和内容到控制台
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