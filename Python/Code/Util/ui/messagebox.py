from tkinter import Tk, Toplevel, messagebox

class MessageBox:
    def __init__(self, root=None):
        self.mb = None

        # If their is a parent, set messagebox as a child
        if root:
            self.mb = Toplevel(master=root)
        # Else, let messagebox works independently of any Toplevel widgets
        else:
            self.mb = Tk()

        self.mb.withdraw()                       # Hide main window
        self.mb.attributes('-topmost', True)     # Always on top

    def show_error(self, msg):
        messagebox.showerror("Error", msg, parent=self.mb)

    def show_warning(self, msg):
        messagebox.showwarning("Warning", msg, parent=self.mb)

    def show_info(self, msg):
        messagebox.showinfo("Information", msg, parent=self.mb)

    def show_yesnoquestion(self, title, msg, icon='question'): # icon must be 'error', 'info', 'question', or 'warning'
        return messagebox.askquestion(title, msg, icon=icon, default='no', parent=self.mb)