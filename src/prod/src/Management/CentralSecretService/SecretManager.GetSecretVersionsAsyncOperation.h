// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Management
{
    namespace CentralSecretService
    {
        class SecretManager::GetSecretVersionsAsyncOperation
            : public SecretManager::SecretsAsyncOperation
        {
        public:
            GetSecretVersionsAsyncOperation(
                Store::IReplicatedStore * replicatedStore,
                Store::PartitionedReplicaId const & partitionedReplicaId,
                std::vector<SecretReference> const & secretReferences,
                Common::TimeSpan const & timeout,
                Common::AsyncCallback const & callback,
                Common::AsyncOperationSPtr const & parent,
                Common::ActivityId const & activityId);

            static Common::ErrorCode End(
                Common::AsyncOperationSPtr const & asyncOperation,
                __out std::vector<SecretReference> & secretReferences);

        protected:
            virtual void OnStart(AsyncOperationSPtr const & thisSPtr) override;

            virtual Common::StringLiteral const & get_TraceComponent() const override;

        private:
            std::vector<SecretReference> const incomingSecretReferences_;
            std::vector<SecretReference> retrievedSecretVersionReferences_;

            static Common::StringLiteral const TraceComponent;

            Common::ErrorCode ValidateSecretReferences();
        };
    }
}