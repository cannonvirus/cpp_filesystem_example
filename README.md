<h1 align="center">Welcome to cpp_filesystem_example 👋</h1>
<p>
  <img alt="Version" src="https://img.shields.io/badge/version-1.0-blue.svg?cacheSeconds=2592000" />
</p>

> this project is sample code to use easily handling file or folder.

## fs_exists

```cpp
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
```

- 파일이 있는지, 폴더인지 유무를 알 수 있는 샘플코드

## search_path

```cpp
void search_path(string cpp_path)
{
    fs::path p(cpp_path);

    cout << "current path : " << fs::current_path() << endl;
    cout << "[main.cpp] relative path : " << p.relative_path() << endl;
    cout << "[main.cpp] absolute path : " << fs::canonical(p) << endl;
}
```

- 파일의 절대, 상대경로를 알 수 있음

## view_dir

```cpp
void view_dir(string dir_path)
{
    for (const fs::directory_entry &entry :
         fs::directory_iterator(dir_path))
    {
        std::cout << entry.path() << std::endl;
    }
}
```

- 폴더 내 파일구조를 볼 수 있음. tree 와 비슷함.

## create_folder

```cpp
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
```

- 폴더를 생성하는 함수

## copy_folder

```cpp
void copy_folder(string main_dir, string target_dir)
{
    fs::path from(main_dir);
    fs::path to(target_dir);

    fs::copy(from, to, fs::copy_options::recursive);
}
```

- 폴더를 복사하는 함수

## remove_file

```cpp
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
```

- 파일 및 폴더를 삭제하는 함수

## Run tests

```sh
mkdir build
cd build

cmake ..
make

cd ..
./bin/filesystem_test
```

## Author

👤 **cannonvirus**

* Github: [@cannonvirus](https://github.com/cannonvirus)

## Show your support

Give a ⭐️ if this project helped you!

***
_This README was generated with ❤️ by [readme-md-generator](https://github.com/kefranabg/readme-md-generator)_