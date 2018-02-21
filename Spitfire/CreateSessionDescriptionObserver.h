#pragma once


#include "api/peerconnectioninterface.h"
#include "api/jsep.h"



namespace Spitfire {

	class RtcConductor;

	namespace Observers
	{
		class CreateSessionDescriptionObserver : public webrtc::CreateSessionDescriptionObserver
		{
		public:


			void OnSuccess(webrtc::SessionDescriptionInterface * desc) override;
			void OnFailure(const std::string & error) override;
			explicit CreateSessionDescriptionObserver(RtcConductor* manager);
			~CreateSessionDescriptionObserver();

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