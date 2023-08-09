# Windows Development Kit

WDK is a C++ Wrapper for the Windows API.
It is designed to be a simple OOP wrapper for the Windows API, and is not intended to be a full fledged framework.

# Usage

Include the WDK.h header file in your project, and link against the WDK.lib library.
Alternatively, you could include the WDK project in your solution and add it as a reference for your project.

# Example

```cpp
#include <WDK/WDK.h>

int main(int _argc, char* _argv[])
{
    WDK::Window wnd("WDK", WDK::Rectangle(0, 0, 800, 600));

    wnd.Open();

    while (wnd.IsOpen())
    {
        wnd.Update();

        //Do something stoopid here
    }

    return 0;
}
```

# License

This project is licensed under the Apache License 2.0 - see the [LICENSE](LICENSE) file for details