#pragma once
namespace adas
{
    template<typename T>
    class Singleton final
    {
    public:
        static T& Instance(void) noexcept
        {
            static T instance;
            return instance;
        }

        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) noexcept = delete;

    private:
        Singleton(void) noexcept = default;
        ~Singleton(void) noexcept = default;
        };

}