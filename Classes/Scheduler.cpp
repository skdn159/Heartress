#include "Scheduler.h"
#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <winsock2.h>
#include <windows.h>
#include <process.h>
#include <assert.h>
#include <limits.h>
#include <vector>
#include <map>
#include <algorithm>
#include <atomic>
#include <typeinfo>

Scheduler::Scheduler()
{
	mCurrentTick = GetTickCount();
}


void Scheduler::PushTask(RefCountable* owner, const Task& task, uint32_t after)
{
	int64_t dueTimeTick = after + mCurrentTick;

	owner->IncRefCount(); ///< for scheduler
	mTaskQueue.push(JobElement(owner, task, dueTimeTick));
}


void Scheduler::DoTasks()
{
	/// tick update
	mCurrentTick = GetTickCount();

	while (!mTaskQueue.empty())
	{
		JobElement timerJobElem = mTaskQueue.top();

		if (mCurrentTick < timerJobElem.mExecutionTick)
			break;

		/// do task!
		timerJobElem.mTask();

		timerJobElem.mOwner->DecRefCount(); ///< for scheduler

		mTaskQueue.pop();
	}
}
