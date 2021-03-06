/**
* @file DelegateMListener.h
* @brief Delegate to get all information related to a MEGA account.
*
* (c) 2013-2014 by Mega Limited, Auckland, New Zealand
*
* This file is part of the MEGA SDK - Client Access Engine.
*
* Applications using the MEGA API must present a valid application key
* and comply with the the rules set forth in the Terms of Service.
*
* The MEGA SDK is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*
* @copyright Simplified (2-clause) BSD License.
*
* You should have received a copy of the license along with this
* program.
*/

#pragma once

#include "MegaSDK.h"
#include "MTransfer.h"
#include "MRequest.h"
#include "MError.h"

namespace mega
{
	ref class MegaSDK;

	using namespace Windows::Foundation;
	using Platform::String;

	private class DelegateMListener : public MegaListener
	{
	public:
		DelegateMListener(MegaSDK^ megaSDK, MListenerInterface^ listener);
		MListenerInterface^ getUserListener();

		void onRequestStart(MegaApi* api, MegaRequest* request);
		void onRequestFinish(MegaApi* api, MegaRequest* request, MegaError* e);
		void onRequestUpdate(MegaApi* api, MegaRequest* request);
		void onRequestTemporaryError(MegaApi* api, MegaRequest* request, MegaError* e);
		void onTransferStart(MegaApi* api, MegaTransfer* transfer);
		void onTransferFinish(MegaApi* api, MegaTransfer* transfer, MegaError* e);
		void onTransferUpdate(MegaApi* api, MegaTransfer* transfer);
		void onTransferTemporaryError(MegaApi* api, MegaTransfer* transfer, MegaError* e);
		void onUsersUpdate(MegaApi* api, MegaUserList *users);
		void onNodesUpdate(MegaApi* api, MegaNodeList *nodes);
		void onReloadNeeded(MegaApi* api);

	private:
		MegaSDK^ megaSDK;
		MListenerInterface^ listener;
	};
}
