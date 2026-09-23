module;

#include <vector>

export module resources.signal;

export template<typename... Args>
class Signal {
public:
	using Callback = void(*)(Args...);

	constexpr void Fire(Args&... args) const {
		for (const auto& callback : callbacks) {
			callback(args...);
		}
	}

	constexpr void Connect(Callback callback) {
		callbacks.push_back(callback);
	}
private:
	std::vector<Callback> callbacks{};
};