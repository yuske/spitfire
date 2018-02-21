#pragma once
#include "api/jsep.h"

namespace Spitfire {

	class RtcConductor;

	namespace Observers
	{
		 class SetSessionDescriptionObserver : public webrtc::SetSessionDescriptionObserver
		{
		public:

			~SetSessionDescriptionObserver();
			 explicit SetSessionDescriptionObserver(RtcConductor* manager);

			 void OnSuccess() override;
			 void OnFailure(const std::string& error) override;

			void AddRef() const override
			{
				//return 0;
			};

			rtc::RefCountReleaseStatus Release() const override
			{
				return rtc::RefCountReleaseStatus::kDroppedLastRef;
			};

		private:
			RtcConductor * _manager;
		};
	}
}