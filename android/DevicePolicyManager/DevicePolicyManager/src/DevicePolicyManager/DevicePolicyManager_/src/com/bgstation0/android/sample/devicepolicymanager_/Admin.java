package com.bgstation0.android.sample.devicepolicymanager_;

import android.app.admin.DeviceAdminReceiver;
import android.content.Context;
import android.content.Intent;

public class Admin extends DeviceAdminReceiver {

	@Override
	public void onEnabled(Context context, Intent intent){
		
	}
	
	@Override
	public void onDisabled(Context context, Intent intent){
		
	}
	
}