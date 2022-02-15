#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

void fs_exists(string cpp_path)
{
    // fs::path p("../main.cpp");
    fs::path p(cpp_path);
    cout << p;
    if (fs::exists(p))
    {
        if (fs::is_regular_file(p))
        {
            cout << " : file O, dir X" << endl;
        }
        else
        {
            cout << " : file X, dir O" << endl;
        }
    }

    // ? directory 인지 아닌지 알 수 있는 코드
    // cout << fs::is_directory(p) << endl;
}

void search_path(string cpp_path)
{
    fs::path p(cpp_path);

    cout << "current path : " << fs::current_path() << endl;
    cout << "[main.cpp] relative path : " << p.relative_path() << endl;
    // cout << "[main.cpp] absolute path : " << fs::absolute(p) << endl;
    cout << "[main.cpp] absolute path : " << fs::canonical(p) << endl;
}

void view_dir(string dir_path)
{
    for (const fs::directory_entry &entry :
         fs::directory_iterator(dir_path))
    {
        std::cout << entry.path() << std::endl;
    }
}

void create_folder(string dir_path, bool ignore_parent_dir)
{
    if (!fs::exists(dir_path))
    {
        if (ignore_parent_dir)
        {
            fs::create_directories(dir_path);
        }
        else
        {
            fs::create_directory(dir_path);
        }
    }
    else
    {
        cout << "exist folder" << endl;
    }
}

// ? main_dir 안에 있는 파일, 폴더들이 target_dir 아래로 복사됨
void copy_folder(string main_dir, string target_dir)
{
    fs::path from(main_dir);
    fs::path to(target_dir);

    fs::copy(from, to, fs::copy_options::recursive);
}

// ? file_path가 빈 폴더여도 지울 수 있음
// ? for문으로 if문 해당 파일 모두 지우기는 iterator를 초기화 해야함
void remove_file(string file_path, bool ignore_exist_file)
{
    if (fs::exists(file_path))
    {
        if (ignore_exist_file)
        {
            fs::remove_all(file_path);
        }
        else
        {
            fs::remove(file_path);
        }
    }
}

int main()
{
    string cpp_path = "/works/cpp_filesystem_example/main.cpp";
    string dir_path = "/works/cpp_filesystem_example/";
    string cre_path = "/works/cpp_filesystem_example/sample/apple/banana/";
    // fs_exists(cpp_path);
    // search_path(cpp_path);
    // view_dir(dir_path);
    // create_folder(cre_path, true);
    // copy_folder("/works/cpp_filesystem_example/sample/apple", "/works/cpp_filesystem_example/sample/a");
    remove_file("/works/cpp_filesystem_example/sample/apple", true);

    return 0;
}
