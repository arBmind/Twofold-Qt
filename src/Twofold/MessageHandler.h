/* Twofold-Qt
 * (C) Copyright 2014 HicknHack Software GmbH
 *
 * The original code can be found at:
 *     https://github.com/hicknhack-software/Twofold-Qt
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "Twofold/SourceMap.h"
#include "Twofold/BacktraceFilePosition.h"

#include <memory>

namespace Twofold {

class MessageHandler;
using MessageHandlerPtr = std::shared_ptr<MessageHandler> ;

enum class MessageType {
    Info,
    Warning,
    Error
};

/**
 * @brief simple implementation of a message handler
 */
class MessageHandler
{
protected:
    using Type = Twofold::MessageType;
    using Text = QString;
    using Position = Twofold::FileLineColumnPosition;
    using BacktracePosition = Twofold::BacktraceFilePosition;
    using PositionStack = Twofold::BacktraceFilePositionList;

public:
    virtual ~MessageHandler() = default;

    virtual void message(Type type, const Text &text);

    virtual void templateMessage(Type type,
                                 const Position &position,
                                 const Text &text);

    virtual void javaScriptMessage(Type type,
                                   const PositionStack &positionStack,
                                   const Text &text);
};

} // namespace Twofold
