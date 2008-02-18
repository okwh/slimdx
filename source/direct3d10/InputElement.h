/*
* Copyright (c) 2007-2008 SlimDX Group
* 
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

//using namespace System;
//using namespace System::Runtime::InteropServices;

#include "../dxgi/Enums.h"

#include "Enums.h"

namespace SlimDX
{
	namespace Direct3D10
	{
		[System::Runtime::InteropServices::StructLayout( System::Runtime::InteropServices::LayoutKind::Sequential )]
		public value class InputElement
		{
		private:
            System::String^ semanticName;
            int semanticIndex;
            DXGI::Format aFormat;
            int inputSlot;
            int alignedByteOffset;
            InputClassification inputSlotClass;
            int instanceDataStepRate;

		public:
			property System::String^ SemanticName
            {
                System::String^ get() { return semanticName; }
                void set( System::String^ value ) { semanticName = value; }
            }

            property int SemanticIndex
            {
                int get() { return semanticIndex; }
                void set( int value ) { semanticIndex = value; }
            }

            property DXGI::Format AFormat
            {
                DXGI::Format get() { return aFormat; }
                void set( DXGI::Format value ) { aFormat = value; }
            }

            property int InputSlot
            {
                int get() { return inputSlot; }
                void set( int value ) { inputSlot = value; }
            }

            property int AlignedByteOffset
            {
                int get() { return alignedByteOffset; }
                void set( int value ) { alignedByteOffset = value; }
            }

            property InputClassification InputSlotClass
            {
                InputClassification get() { return inputSlotClass; }
                void set( InputClassification value ) { inputSlotClass = value; }
            }

            property int InstanceDataStepRate
            {
                int get() { return instanceDataStepRate; }
                void set( int value ) { instanceDataStepRate = value; }
            }

			InputElement( System::String^ name, int index, DXGI::Format format, int offset, int slot  )
			{
				SemanticName = name;
				SemanticIndex = index;
				AFormat = format;
				InputSlot = slot;
				AlignedByteOffset = offset;
				InputSlotClass = InputClassification::PerVertexData;
				InstanceDataStepRate = 0;
			}

			InputElement( System::String^ name, int index, DXGI::Format format, int offset, int slot, InputClassification slotClass, int stepRate )
			{
				SemanticName = name;
				SemanticIndex = index;
				AFormat = format;
				InputSlot = slot;
				AlignedByteOffset = offset;
				InputSlotClass = slotClass;
				InstanceDataStepRate = stepRate;
			}
		};
	}
};