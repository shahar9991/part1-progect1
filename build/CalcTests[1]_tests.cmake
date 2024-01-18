add_test( SumTest.BasicTest [==[/mnt/c/Users/Yael/OneDrive/שנה ג סמסטר א/תכנות מתקדם/project1/part1-progect1/build/CalcTests]==] [==[--gtest_filter=SumTest.BasicTest]==] --gtest_also_run_disabled_tests)
set_tests_properties( SumTest.BasicTest PROPERTIES WORKING_DIRECTORY [==[/mnt/c/Users/Yael/OneDrive/שנה ג סמסטר א/תכנות מתקדם/project1/part1-progect1/build]==])
set( CalcTests_TESTS SumTest.BasicTest)
