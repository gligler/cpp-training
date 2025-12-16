#pragma once
namespace adas
{
    template<typename T>
    class Singleton final
    {
    public:
        static T& Instance(void)
        {
            static T instance;
            return instance;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) noexcept = delete;

    private:
        Singleton(void)  = default;
        ~Singleton(void) = default;
        };

}