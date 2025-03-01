#pragma once
#include <vector>
#include <string>
#include <memory>
#include "Singleton.h"

namespace kob
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void Start();
		void Update();
		void LateUpdate();
		void FixedUpdate();
		void Render() const;
		void ImGuiRenderUpdate();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_scenes;
	};
}
