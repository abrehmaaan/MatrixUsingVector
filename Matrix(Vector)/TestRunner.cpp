#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
//#include"Matrix.hpp"
using namespace doctest;
//using namespace zich;

const int MIN_TESTS = 20;


struct ReporterGrader : public ConsoleReporter {
    ReporterGrader(const ContextOptions& input_options)
        : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats& run_stats) override {
        ConsoleReporter::test_run_end(run_stats);
        int numAsserts = run_stats.numAsserts >= MIN_TESTS ? run_stats.numAsserts : MIN_TESTS;
        float grade = (run_stats.numAsserts - run_stats.numAssertsFailed) * 100 / numAsserts;
        // std::cout << "Grade: " << grade << std::endl;
    }
};

REGISTER_REPORTER("grader", /*priority=*/1, ReporterGrader);

int main(int argc, char** argv) {
    Context context;
    context.addFilter("reporters", "grader");
    return context.run();
    //vector<double> identity_3 = { 1,0,0,0,1,0,0,0,1 };//3x3
    //Matrix mat_identity_3(identity_3, 3, 3);
    //vector<double> vec1 = { 1,1,1,1,1,1,1,1,1 };//3x3
    //vector<double> arr = { 2,1,1,1,2,1,1,1,2 };//3x3   arr = identity_3 + vec1
    //vector<double> vec2 = { 1,0,0,0,0,1,0,0,0,0,1,0 };//3x4
    //vector<double> identity_4 = { 1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };//4x4
    //vector<double> _vec_ = { 1,1,1,1,1,1,1,1,1,1,1,1 };//4x3
    //Matrix _mat_(_vec_, 4, 3);
    //Matrix mat1(vec1, 3, 3);
    //Matrix mat_arr(arr, 3, 3);
    //Matrix mat2(vec2, 3, 4);
    //Matrix mat_identity_4(identity_4, 4, 4);
    //for (double i = 1; i < 500; i++)
    //{
    //    int random = rand() % 1000;
    //    vector<double> vec1 = { i * random,i * random,i * random,i * random,i * random,i * random,i * random,i * random,i * random };
    //    Matrix matrix(vec1, 3, 3);
    //    cout<< ((matrix * mat_identity_3) == matrix);

    //    vector<double> arr1 = { i,i,i,i,i,i,i,i,i };//3x3

    //    vector<double> arr = { pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2),pow(i,2) };//3x3
    //    Matrix mat1(arr1, 3, 3);
    //    Matrix mat(arr, 3, 3);
    //    cout<< ((mat1 * mat1) != mat);
    //    cout<<((mat_identity_3 * mat_identity_3) == mat_identity_3);
    //}

}
