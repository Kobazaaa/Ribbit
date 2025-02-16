#pragma once

namespace rib
{
	class GameObject;

	class Component
	{
	public:
		//--------------------------------------------------
		//    Constructor and Destructor
		//--------------------------------------------------
		explicit Component(GameObject* parent);
		virtual ~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) = delete;


		//--------------------------------------------------
		//    Loop
		//--------------------------------------------------
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render()				const;


		//--------------------------------------------------
		//    Accessors & Mutators
		//--------------------------------------------------
		void FlagForDeletion();
		bool IsFlaggedForDeletion()			const;

	protected:
		GameObject* m_pParent{};

	private:
		bool m_DeletionFlag{ false };

	};
}
