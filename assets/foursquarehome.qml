import Cascades 4.0

Container {
    layout: DockLayout {
            }
    ImageView {
        image: "assets://images/background"
        preferredWidth: 1024
        preferredHeight: 600
    }
    Container {
        layout: StackLayout {}
        layoutProperties: DockLayoutProperties {
            horizontalAlignment: HorizontalAlignment.Center;
            verticalAlignment: VerticalAlignment.Center;
        }
        topMargin: 10
        bottomMargin: 10
        preferredWidth: 1024
        preferredHeight: 600
        Label {
            objectName: "userName"
            topMargin: 10; bottomMargin: 10;
            font: SystemFont.H2
            textColor: Color.create("#ffffffff")
            layoutProperties: StackLayoutProperties {verticalAlignment: VerticalAlignment.Top; horizontalAlignment: HorizontalAlignment.Center;}
        }
        Button {
		    objectName: "logoutButton"
		    text: "Logout"
        }
    }
}