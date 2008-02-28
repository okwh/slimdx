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

#include "../ComObject.h"

#include "DeviceChild.h"
#include "Enums.h"
#include "Factory.h"

using System::Runtime::InteropServices::OutAttribute;

namespace SlimDX
{
	namespace DXGI
	{
		ref class Device;
		ref class Factory;
		ref class Output;
		value class FrameStatistics;
		value class ModeDescription;
		value class SwapChainDescription;
		
		/// <remarks>
		/// Holds one or more surfaces that store rendered data prior to presenting
		/// that data to an output.
		/// </remarks>
		public ref class SwapChain : public DeviceChild
		{
			COMOBJECT(IDXGISwapChain, SwapChain);
		
		public:
			/// <summary>
			/// Gets the swap chain's description.
			/// </summary>
			property SwapChainDescription Description
			{
				SwapChainDescription get();
			}
			
			/// <summary>
			/// Gets statistics about recent frames.
			/// </summary>
			property DXGI::FrameStatistics FrameStatistics
			{
				DXGI::FrameStatistics get();
			}
			
			/// <summary>
			/// Gets the number of times this swap chain's Present method has been called.
			/// </summary>
			property int PresentCount
			{
				int get();
			}
			
			/// <summary>
			/// Constructs a SwapChain from an unmanaged pointer.
			/// </summary>
			/// <param name="pointer">The unmanaged IDXGISwapChain pointer.</param>
			static SwapChain^ FromPointer( System::IntPtr pointer );
			
			/// <summary>
			/// Constructs a SwapChain.
			/// </summary>
			/// <param name="factory">The factory used to create the swap chain.</param>
			/// <param name="device">The device used to present images to the swap chain.</param>
			/// <param name="device">Swap chain properties.</param>
			SwapChain( Factory^ factory, ComObject^ device, SwapChainDescription description );
			
			/// <summary>
			/// Gets a swap chain back buffer.
			/// </summary>
			/// <param name="buffer">The index of the desired buffer.</param>
			/// <returns>The buffer interface, or null on failure.</return>
			generic< typename T > where T : ComObject, ref class
			T GetBuffer( int buffer );
			
			/// <summary>
			/// Gets the output containing the swap chain target.
			/// </summary>
			/// <returns>The output, or null on failure.</return>
			Output^ GetContainingOutput();
			
			/// <summary>
			/// Gets the full screen state.
			/// </summary>
			/// <param name="isFullScreen">Receives a value indicating if the swap chain is running in full screen mode.</param>
			/// <param name="target">Receives the full screen ouput if the swap chain is in full screen mode. Otherwise ignored.</param>
			/// <returns>A Result code.</return>
			Result GetFullScreenState( [Out] bool% isFullScreen, [Out] Output^% target );
			
			/// <summary>
			/// Sets the full screen state.
			/// </summary>
			/// <param name="isFullScreen">Set to true for full screen mode, false for windowed mode.</param>
			/// <param name="target">If the current display mode is full screen, this parameter must be the
			/// output containing the swap chain; otherwise, this parameter is ignored. If you set this parameter
			/// to null, DXGI will choose the output based on the swap-chain's device and the output window's placement.</param>
			/// <returns>A Result code.</return>
			Result SetFullScreenState( bool isFullScreen, Output^ target );
			
			/// <summary>
			/// Changes the swap chain's back buffer size, format, and count.
			/// </summary>
			/// <param name="count">The new back buffer count.</param>
			/// <param name="count">The new back buffer width.</param>
			/// <param name="count">The new back buffer height.</param>
			/// <param name="count">The new back buffer format.</param>
			/// <param name="count">Flags controlling swap chain functionality.</param>
			/// <returns>A Result code.</return>
			Result ResizeBuffers( int count, int width, int height, Format format, SwapChainFlags flags );
			
			/// <summary>
			/// Changes the output target's size.
			/// </summary>
			/// <param name="description">Properties of the new output display mode.</param>
			/// <returns>A Result code.</return>
			Result ResizeTarget( ModeDescription description );
			
			/// <summary>
			/// Presents a rendered image to the attached output.
			/// </summary>
			/// <param name="syncInterval">Specified how to synchronize the presentation with the vertical blank interrupt. 0
			/// indicates that presentation should occur immediately, without synchronization. Any other value indicates that
			/// presentation should be synchonized with the specified next vertical blank.</param>
			/// <param name="flags">Flags controlling presentation behavior.</param>
			/// <returns>A Result code.</return>
			Result Present( int syncInterval, PresentFlags flags );
		};
	}
};