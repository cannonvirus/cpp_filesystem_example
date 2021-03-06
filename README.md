<h1 align="center">Welcome to cpp_filesystem_example π</h1>
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

    // ? directory μΈμ§ μλμ§ μ μ μλ μ½λ
    // cout << fs::is_directory(p) << endl;
}
```

- νμΌμ΄ μλμ§, ν΄λμΈμ§ μ λ¬΄λ₯Ό μ μ μλ μνμ½λ

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

- νμΌμ μ λ, μλκ²½λ‘λ₯Ό μ μ μμ

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

- ν΄λ λ΄ νμΌκ΅¬μ‘°λ₯Ό λ³Ό μ μμ. tree μ λΉμ·ν¨.

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

- ν΄λλ₯Ό μμ±νλ ν¨μ

## copy_folder

```cpp
void copy_folder(string main_dir, string target_dir)
{
    fs::path from(main_dir);
    fs::path to(target_dir);

    fs::copy(from, to, fs::copy_options::recursive);
}
```

- ν΄λλ₯Ό λ³΅μ¬νλ ν¨μ

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

- νμΌ λ° ν΄λλ₯Ό μ­μ νλ ν¨μ

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

π€ **cannonvirus**

* Github: [@cannonvirus](https://github.com/cannonvirus)

## Show your support

Give a β­οΈ if this project helped you!

***
_This README was generated with β€οΈ by [readme-md-generator](https://github.com/kefranabg/readme-md-generator)_