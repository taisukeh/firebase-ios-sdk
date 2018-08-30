/*
 * Copyright 2018 Google
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_REMOTE_GRPC_STREAM_OBSERVER_H_
#define FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_REMOTE_GRPC_STREAM_OBSERVER_H_

#include <memory>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

#include "Firestore/core/src/firebase/firestore/remote/grpc_stream_operation.h"
#include "Firestore/core/src/firebase/firestore/util/async_queue.h"
#include "Firestore/core/src/firebase/firestore/util/status.h"
#include "grpcpp/client_context.h"
#include "grpcpp/generic/generic_stub.h"
#include "grpcpp/support/byte_buffer.h"

namespace firebase {
namespace firestore {
namespace remote {

/** Observer that gets notified of events on a gRPC stream. */
class GrpcStreamObserver {
 public:
  virtual ~GrpcStreamObserver() {
  }

  // Stream has been successfully established.
  virtual void OnStreamStart() = 0;
  // A message has been received from the server.
  virtual void OnStreamRead(const grpc::ByteBuffer& message) = 0;
  // Connection has been broken, perhaps by the server.
  virtual void OnStreamError(const util::Status& status) = 0;
};

}  // namespace remote
}  // namespace firestore
}  // namespace firebase

#endif  // FIRESTORE_CORE_SRC_FIREBASE_FIRESTORE_REMOTE_GRPC_STREAM_OBSERVER_H_
