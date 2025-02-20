#include <exception>
#include <functional>
#include <optional>

template <typename Result, typename Exception = std::exception>
std::optional<Result> DoWithRetry(std::function<Result()> func,
                                  int retryCount, int sleepTime, bool throwLast)
{   
    std::function<Result> tmp;
    for (int i = 0; i < retryCount +1; i++)
    {
        try
        {
            return func();
        }
        catch(const Exception)
        {   
            if (i==retryCount && throwLast)
            {
                throw;
            }else
            {
                Sleep(sleepTime);    
            }
            
            //std::cerr << e.what() << '\n';
        }

        return {};
    }
}