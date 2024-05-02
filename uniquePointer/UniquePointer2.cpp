#include <iostream>
#include <memory>
#include <vector>
#include <utility>
using namespace std;

// Definindo uma classe fictícia Widget para evitar erros de compilação
class Widget {
public:
    int val;
    Widget(int value) : val(value) {}
};

// Função fictícia use_widget para evitar erros de compilação
void use_widget(Widget& widget) {
    // Faz algo com o widget
}

// Implementação de um ponteiro único personalizado
template <class T>
class my_unique_ptr {
public:
    my_unique_ptr() noexcept : my_unique_ptr(nullptr) {}
    explicit my_unique_ptr(T *ptr) noexcept : m_ptr(ptr) {}

    my_unique_ptr(const my_unique_ptr &) = delete;
    my_unique_ptr &operator=(const my_unique_ptr &) = delete;

    my_unique_ptr(my_unique_ptr &&other) noexcept : m_ptr(other.release()) {}

    my_unique_ptr &operator=(my_unique_ptr &&other) noexcept {
        if (this != &other) {
            reset(other.release());
        }
        return *this;
    }

    explicit operator bool() const noexcept {
        return static_cast<bool>(m_ptr);
    }

    T *get() const noexcept {
        return m_ptr;
    }

    T &operator->() const noexcept {
        return *m_ptr;
    }

    T &operator*() const noexcept {
        return *m_ptr;
    }

    T *release() noexcept {
        return exchange(m_ptr, nullptr);
    }

    void reset(T *ptr = nullptr) noexcept {
        T *old = exchange(m_ptr, ptr);
        if (old) {
            delete old;
        }
    }

    ~my_unique_ptr() noexcept {
        if (m_ptr) {
            delete m_ptr;
        }
    }

private:
    T *m_ptr;
};

template <class T, class... Args>
my_unique_ptr<T> make_my_unique(Args &&... args) {
    return my_unique_ptr<T>(new T(forward<Args>(args)...));
}

void vector_example() {
    vector<my_unique_ptr<Widget>> widgets;
    const size_t count = 5;
    widgets.reserve(count);
    for (size_t i = 0; i < count; ++i) {
        widgets.push_back(make_my_unique<Widget>(i));
    }
    for (const auto &widget : widgets) {
        use_widget(*widget);
    }
    widgets.pop_back();

    my_unique_ptr<Widget> last = move(widgets.back());
    widgets.pop_back();

    cout << "O ultimo elemento foi: " << last.get()->val << endl;
}

int main() {
    int *xp = new int(42);
    *xp = 0;
    delete xp;

    return 0;
}
