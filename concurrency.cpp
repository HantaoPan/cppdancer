#include <omp.h>
#include <iostream>
#include "BS_thread_pool.hpp"
#include <thread>
#include <vector>
#include <windows.h>¡¡


int main() {

    BS::thread_pool pool;


    BS::multi_future<void> mf = pool.parallelize_loop(1, 101,
        [](const int a, const int b)
        {

            for (int i = a; i < b; ++i) {
                //std::cout << "Hello, world" << std::endl;
                Sleep(30);
                if (i == 80)throw"error?";
            }
        });
    try {
        mf.get();
        std::cout << "Succeed" << std::endl;
    }
    catch (...) {
        std::cout << "Catch error!" << std::endl;
    }

    return 0;
}


//long int sum{};
//try {
//    //#pragma omp parallel for
//    for (int i = 0; i <= 1000; ++i) 
//        pool.submit([&sum, i]
//            {
//                std::string k{"0"};
//                k = "eat time"; k = "kill time"; k = "consume time";
//                std::vector<int> eattime{ 0, 1, 2, 3, 4 };
//                eattime.resize(10); eattime.resize(20); eattime.resize(30);
//                Sleep(1);
//                sum += i;
//                if (i == 800)
//                    throw "error";
//            }); 
//    pool.wait_for_tasks();
//    
//}
//catch (...) {
//    std::cout << "catch error!" << '\n';
//}

//long int sum{};
//try {
//    pool.parallelize_loop(1001,
//        [&sum](const int a, const int b)
//        {
//            for (int i = a; i < b; ++i) {
//                Sleep(1);
//                sum += i;
//                if (i == 800)
//                    throw "error";
//            }
//        })
//        .wait();
//
//}
//catch (...) {
//    std::cout << "catch error!" << '\n';
//}

//
//auto my_future = accumulate();
//std::cout << my_future;

//auto my_future = pool.submit(accumulate);
//std::cout << my_future.get();

//try {
//    int result = my_future.get();
//    //std::cout << result;
//}
//catch (const std::exception& e)
//{
//    std::cout<<"Catch error!";
//}